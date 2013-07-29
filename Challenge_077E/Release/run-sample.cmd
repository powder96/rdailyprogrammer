set size=%1
echo Challenge 077E (size: %size%)
echo ==========================
if not exist output%size%.txt goto actualOutput
echo Expected output
echo ---------------
type output%size%.txt
echo.
:actualOutput
echo Actual output
echo -------------
Challenge_077E %size%
echo.
pause