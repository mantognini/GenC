#!/usr/bin/env fish

# Run the benchmarks for Scala, Clang & GCC (with -O0, -O1 & -O3)

ulimit -sS 1048576

set leonBase (dirname (which leon))
set leonLib "$leonBase/library/"

set src ImageProcessingVLABenchmark

set ccs clang gcc
set opts 0 1 3

set dirScala outputs/scala

set base (pwd)
set csv $base/runtimes.csv
set outClasses $base/out-classes

# Compile each version of the benchmark
rm -rf "$outClasses"
mkdir "$outClasses"
echo "fsc -deprecation (find $leonLib -name '*.scala') $src.scala -d $outClasses"
fsc -deprecation (find $leonLib -name '*.scala') $src.scala -d "$outClasses"
echo "leon --genc $src.scala --o=$src.c"
leon --genc $src.scala --o=$src.c

for cc in $ccs
  for O in $opts
    echo "$cc --std=c99 $src.c -O$O -o $src.$cc.$O"
    eval $cc --std=c99 $src.c -O$O -o $src.$cc.$O
  end
end

# Run each version

echo "version;input;filter;runtime[ms]" > "$csv"

for cc in $ccs
  for O in $opts
    set d outputs/$cc.$O
    rm -rf "$d"
    mkdir -p "$d"
    pushd "$d"
      echo "Running $cc.$O version"
      echo "$base/$src.$cc.$O"
      bash -c \"$base/$src.$cc.$O\" | sed -u -e "s/^/$cc.$O;/" -e "s#../../../##" -e "s#.bmp##" | tee -a "$csv"
    popd
  end
end

rm -rf "$dirScala"
mkdir -p "$dirScala"
pushd "$dirScala"
  echo "Running Scala version"
  echo "scala -cp $outClasses $src"
  scala -cp "$outClasses" $src | sed -u -e "s/^/scala;/" -e "s#../../../##" -e "s#.bmp##" | tee -a "$csv"
popd

