for /l %%x in (1, 1, 2) do ( lualatex -shell-escape --jobname=main-without-notes "\input{main}" )

for /l %%x in (1, 1, 2) do ( lualatex -shell-escape --jobname=main-with-notes "\def\NOTES{}\input{main}" )

del *aux
del *gz
del *log
del *nav
del *out
del *snm
del *toc
del *vrb

