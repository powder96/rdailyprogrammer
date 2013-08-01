@echo off
echo Challenge 086E - Sample %sample%
echo =========================
echo.
echo Input
echo -----
type example.dat
echo.
echo.
echo Compressed
echo ----------
Challenge_086E compress example.dat > example-compressed.dat
type example-compressed.dat
echo.
echo.
echo Decompressed
echo ------------
Challenge_086E decompress example-compressed.dat
echo.
echo.
pause