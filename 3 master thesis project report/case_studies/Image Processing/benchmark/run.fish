#!/usr/bin/env fish

# Run the benchmarks for Scala, Clang & GCC (with -O0, -O1 & -O3)
# NOTE Scala Native version is not run by this script

ulimit -sS 1048576

set leonBase (dirname (which leon))
set leonLib "$leonBase/library/"

set object ImageProcessingVLABenchmark
set srcBase $object

set ccs clang gcc
set opts 0 1 3
set versions vc_enabled vc_disabled vc_removed

set dirScalaBase outputs/scala

set base (pwd)
set csv $base/runtimes.csv
set outClasses $base/out-classes

#
# Compile each C version of the benchmark
#
echo "leon --genc $srcBase.vc_enabled.scala --o=$srcBase.c"
leon --genc $srcBase.vc_enabled.scala --o=$srcBase.c

for cc in $ccs
  for O in $opts
    echo "$cc --std=c99 $src.c -O$O -o $src.$cc.$O"
    eval $cc --std=c99 $src.c -O$O -o $src.$cc.$O
  end
end

#
# Run each C version
#
echo "version;input;filter;runtime[ms]" > "$csv"

for cc in $ccs
  for O in $opts
    set d outputs/$cc.$O
    rm -rf "$d"
    mkdir -p "$d"
    pushd "$d"
      echo "Running $cc.$O version"
      echo "$base/$srcBase.$cc.$O"
      bash -c \"$base/$srcBase.$cc.$O\" | sed -u -e "s/^/$cc.$O;/" -e "s#../../../##" -e "s#.bmp##" | tee -a "$csv"
    popd
  end
end

#
# Run each JVM version
#
for v in $versions
  echo "Running Scala version $v"

  set src "$srcBase.$v"
  set dirScala "$dirScalaBase.$v"

  rm -rf "$outClasses"
  mkdir "$outClasses"

  rm -rf "$dirScala"
  mkdir -p "$dirScala"

  fsc -reset

  echo "fsc -deprecation (find $leonLib -name '*.scala') $src.scala -d $outClasses"
  fsc -deprecation (find $leonLib -name '*.scala') $src.scala -d "$outClasses"

  pushd "$dirScala"
    echo "scala -cp $outClasses $object"
    scala -cp "$outClasses" $object | sed -u -e "s/^/$v;/" -e "s#../../../##" -e "s#.bmp##" | tee -a "$csv"
  popd
end

