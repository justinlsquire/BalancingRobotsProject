#!/bin/bash

lualatex -shell-escape --jobname=main-with-notes "\def\NOTES{}\input{main}"
lualatex -shell-escape --jobname=main-with-notes "\def\NOTES{}\input{main}"

lualatex -shell-escape --jobname=main-only-notes "\def\ONLYNOTES{}\input{main}"
lualatex -shell-escape --jobname=main-only-notes "\def\ONLYNOTES{}\input{main}"

lualatex -shell-escape --jobname=main-handout-without-notes "\def\HANDOUT{}\input{main}"
lualatex -shell-escape --jobname=main-handout-without-notes "\def\HANDOUT{}\input{main}"

lualatex -shell-escape --jobname=main-handout-with-notes "\def\HANDOUT{}\def\NOTES{}\input{main}"
lualatex -shell-escape --jobname=main-handout-with-notes "\def\HANDOUT{}\def\NOTES{}\input{main}"

