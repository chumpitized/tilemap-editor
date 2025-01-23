#include "save.h"
#include "data.h"

#include <fstream>
#include <iostream>
#include <vector>

//draw error message when invalid...
void save() {
	std::vector<u16> trimmedCanvas;
	int rowWidth 		= 0;
	int expectedWidth 	= 0;

	for (auto val : canvas) {
		if (val != 0xffff) {
			rowWidth++;
			trimmedCanvas.push_back(val);
		}
		
		if (val == 0xffff && rowWidth > 0) {
			if (expectedWidth > 0 && rowWidth != expectedWidth) {
				std::cout << "SAVE FAILED" << std::endl;
				std::cout << "ERROR: PUZZLE IS NOT A RECTANGLE" << std::endl;
				return;
			}
			expectedWidth = rowWidth;
			rowWidth = 0;
		}
	}

	int height = (trimmedCanvas.size() / expectedWidth);

	std::fstream file;
    file.open("save/new_puzzle", std::ios::out | std::ios::binary);
 
	//save puzzle to file
	if (file) {
		int length = trimmedCanvas.size() * 2;
		uint8_t buffer[length];

		for (int i = 0; i < trimmedCanvas.size(); i+=2) {
			buffer[i] 		= trimmedCanvas[i] >> 8;
			buffer[i + 1] 	= trimmedCanvas[i]; 
		}
 
		std::cout << "buffer length: " << length << std::endl;

		file.write(reinterpret_cast<char*>(buffer), length);
		file.close();
	}

	std::cout << "~~~SAVING~~~" << std::endl;
	std::cout << "WIDTH: " << expectedWidth << std::endl;
	std::cout << "HEIGHT: " << height << std::endl;
}
