/**
 * Solution for the /r/dailyprogrammer/ challenge #088H (http://reddit.com/y5t0y/)
 * Copyright (C) 2013 powder96 <https://github.com/powder96/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>

bool printBitmapFileAsASCIIArt(char* filename, std::ostream& output, UINT width = 70, UINT grayscaleThreshold = 127) {
	HBITMAP hBmp = (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if(hBmp == NULL)
		return false;
	BITMAP bmp;
	GetObject(hBmp, sizeof(bmp), &bmp);

	HDC hDC = CreateCompatibleDC(NULL);
	SelectObject(hDC, hBmp);

	BITMAPINFO bmpInfo;
	bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmpInfo.bmiHeader.biWidth = bmp.bmWidth;
	bmpInfo.bmiHeader.biHeight = -bmp.bmHeight;
	bmpInfo.bmiHeader.biPlanes = 1;
	bmpInfo.bmiHeader.biBitCount = 32;
	bmpInfo.bmiHeader.biCompression = BI_RGB;        
	bmpInfo.bmiHeader.biSizeImage = 0;

	COLORREF* pixels = new COLORREF[bmp.bmWidth * bmp.bmHeight];
	GetDIBits(hDC, hBmp, 0, bmp.bmHeight, pixels, &bmpInfo, DIB_RGB_COLORS);

	const float aspectRatio = (1.0f * bmp.bmWidth / bmp.bmHeight);
	const int height = (int)((1 / aspectRatio) * width);

	const int xStep = bmp.bmWidth / width;
	const int yStep = bmp.bmHeight / height;
	for(int y = 0; y < bmp.bmHeight; y += yStep) {
		for(int x = 0; x < bmp.bmWidth; x += xStep) {
			const int color1Y = min(y + (int)(yStep / 2.0f), bmp.bmHeight - 1);

			const COLORREF color0 = pixels[      y * bmp.bmWidth + x];
			const COLORREF color1 = pixels[color1Y * bmp.bmWidth + x];
			const UINT grayscale0 = (GetRValue(color0) + GetGValue(color0) + GetBValue(color0)) / 3;
			const UINT grayscale1 = (GetRValue(color1) + GetGValue(color1) + GetBValue(color1)) / 3;
			const bool fill0 = grayscale0 <= grayscaleThreshold;
			const bool fill1 = grayscale1 <= grayscaleThreshold;
			
			if(fill0 && fill1)
				output << (char)219;
			else if(!fill0 && fill1)
				output << (char)220;
			else if(fill0 && !fill1)
				output << (char)223;
			else // !fill0 && !fill1
				output << ' ';
		}
		output << std::endl;
	}

	delete pixels;

	DeleteObject(hBmp);
	DeleteDC(hDC);

	return true;
}

int main(int argc, char** argv) {
	if(argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <string:filename> <uint:width> <uint:threshold>" << std::endl;
		return 1;
	}

	std::stringstream arguments(std::string(argv[2]) + " " + std::string(argv[3]));
	UINT width, threshold;
	arguments >> width >> threshold;

	if(!printBitmapFileAsASCIIArt(argv[1], std::cout, width, threshold))
		std::cerr << "An error has occured." << std::endl;
}