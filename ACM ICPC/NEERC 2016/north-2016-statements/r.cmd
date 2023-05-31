@echo off

if "%~1" == "clean" goto clean

:build

set makepdf=true
set twopass=true
set clean=true

pushd %~dp0

pushd pics
call r build || exit /b 1
popd

setlocal enabledelayedexpansion
if "%twopass%" == "true" (
    latex problems.tex || exit /b 1
)
latex problems.tex || exit /b 1
dvips problems.dvi || exit /b 1
if "%makepdf%" == "true" (
    dvipdfmx -p a4 problems.dvi || exit /b 1
)

