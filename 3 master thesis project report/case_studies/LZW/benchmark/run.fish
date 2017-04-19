#!/usr/bin/env fish

set leonBase (dirname (which leon))
set leonLib "$leonBase/library/"
set base (pwd)
set outClasses $base/out-classes
rm -rf $outClasses
rm -f stats* log* encoded.txt decoded.txt LZW{a,b}.{c,clang,gcc}
# rm -f input*.txt
mkdir $outClasses

# compile all versions
# NOTE using parent directory's version for GenC due to FIS/FOS JVM-friendly implementation
begin

    echo "Compling..." >&2
    time -v fsc -deprecation (find $leonLib -name '*.scala') LZWa.scala LZWb.scala FIS.scala FOS.scala -d "$outClasses"
    echo "Scala: Done" >&2
    time -v leon --genc ../LZWa.scala --o=LZWa.c
    time -v leon --genc ../LZWb.scala --o=LZWb.c
    echo "GenC: Done" >&2
    time -v clang LZWa.c -o LZWa.clang --std=c99 -O3 -DNDEBUG
    time -v clang LZWb.c -o LZWb.clang --std=c99 -O3 -DNDEBUG
    echo "Clang: Done" >&2
    time -v gcc LZWa.c -o LZWa.gcc --std=c99 -O3 -DNDEBUG
    time -v gcc LZWb.c -o LZWb.gcc --std=c99 -O3 -DNDEBUG
    echo "GCC: Done" >&2

end ^| tee log.compile.all.txt


# Check that the input/output is consistent and record stats about compression ratio
function check # argv = $p.$v

    cmp "input.txt" "decoded.txt"
    if [ $status -eq 0 ]
        set orig (wc -c < "input.txt")
        set compressed (wc -c < "encoded.txt")
        set ratio (echo "$compressed / $orig * 100" | bc -l)
        echo "$argv went fine, compression of $ratio"
        echo $ratio >> stats.ratio.$argv.txt
    else
        echo "$argv failed!"
        exit 1
    end

end


set MAX 10
for i in (seq 1 $MAX)

    echo "Run $i or $MAX..."

    # input.txt generation: 755KB of alpha-numeric characters
    # tr -dc A-Za-z0-9 < /dev/urandom | head -c 755K > input.$i.txt
    # cp input.$i.txt input.txt

    # execute all versions
    rm -f "decoded.txt"
    time -v scala -cp "$outClasses" LZWa ^| tee log.jvm.a.$i.txt
    check jvm.a

    rm -f "decoded.txt"
    time -v scala -cp "$outClasses" LZWb ^| tee log.jvm.b.$i.txt
    check jvm.b

    echo "Scala: Done"


    rm -f "decoded.txt"
    time -v ./LZWa.clang ^| tee log.clang.a.$i.txt
    check clang.a

    rm -f "decoded.txt"
    time -v ./LZWb.clang ^| tee log.clang.b.$i.txt
    check clang.b

    echo "Clang: Done"


    rm -f "decoded.txt"
    time -v ./LZWa.gcc ^| tee log.gcc.a.$i.txt
    check gcc.a

    rm -f "decoded.txt"
    time -v ./LZWb.gcc ^| tee log.gcc.b.$i.txt
    check gcc.b

    echo "GCC: Done"

end

# Collect stats
for p in jvm clang gcc
    for v in a b

        # CPU time
        grep -hPo '.*User time \(seconds\): \K.*' log.$p.$v.*.txt > stats.cpu.$p.$v.txt
        awk '{a+=$1} END{print a/NR}' stats.cpu.$p.$v.txt | sed -u -e "s/^/avg = /" >> stats.cpu.$p.$v.txt

        # Max memory
        grep -hPo '.*Maximum resident set size \(kbytes\): \K.*' log.$p.$v.*.txt > stats.ram.$p.$v.txt
        awk '{a+=$1} END{print a/NR}' stats.ram.$p.$v.txt | sed -u -e "s/^/avg = /" >> stats.ram.$p.$v.txt

        # Check that all compressed versions had the same size for all versions
        set baseline stats.ratio.jvm.$v.txt
        cmp $baseline stats.ratio.$p.$v.txt
        if [ $status -ne 0 ]
            echo "$p.$v didn't compress like the baseline!!!" >&2
            exit 2
        end

    end
end

