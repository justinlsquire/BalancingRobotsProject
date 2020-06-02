#!/bin/bash

# clean up
rm *.zip
rm *.pdf

# zip the stuff
zip -r TikZTemplates.zip ./*

# send the stuff
scp -r *.zip damvar@scp.ltu.se:~/public_html/LaTeX/

