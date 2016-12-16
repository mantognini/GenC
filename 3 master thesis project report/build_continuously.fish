#!/usr/bin/env fish

fswatch report.tex report.bib | while read event
    echo ""
    echo "Reading $event @ "(date)
    # make clean
    make all
    # open report.pdf
    and open report.pdf; osascript -e 'tell application "Terminal" to activate'
    echo \a
end

