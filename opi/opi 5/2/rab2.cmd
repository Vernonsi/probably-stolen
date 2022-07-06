@ECHO OFF
IF EXIST out.tmp (
ECHO Error: out.tmp exists
GOTO EXIT
) ELSE (
FIND "zak" *.txt >> out.tmp
echo on
TYPE out.tmp | sort < out.tmp
@echo off
del out.tmp
)
:EXIT
