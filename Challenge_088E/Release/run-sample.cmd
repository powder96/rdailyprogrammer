set sample=%1
set mode=%2
set key=%3
echo Challenge 088E - Sample %sample%
echo =========================
echo.
echo Input
echo -----
echo Key: %key%
type sample%sample%.dat
echo.
echo.
if not exist sample%sample%.txt goto actualOutput
echo Expected output
echo ---------------
type sample%sample%.txt
echo.
echo.
:actualOutput
echo Actual output
echo -------------
Challenge_088E %mode% sample%sample%.dat %key%
echo.
echo.
pause