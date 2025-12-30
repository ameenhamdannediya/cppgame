#include "MapLoader.h"
#include <string>
#include <fstream>




void MapLoader::Load(std::string filename, MapData& Mdata)
{
	bool IsMapExist = false;
	std::string line;
	std::ifstream file(filename);


	if (file.is_open()) {
		while (std::getline(file, line)) {
			if (IsMapExist == false) {

				if (line == "[Map]") {
					std::cout << "reading rmap" << std::endl;

					IsMapExist = true;
					continue;
				}
				else {
					std::cout << "rmap file not valid" << std::endl;
					//break;

				}
			}
			if (IsMapExist) {
				try
				{
					int count = line.find("=");
					std::string variable = line.substr(0, count);
					std::string value = line.substr(count + 1, line.length() - count);

					

					if (variable == "tilesheet")
						Mdata.tilesheet = value;
					else if (variable == "name")
						Mdata.name = value;
					else if (variable == "tileWidth")
						Mdata.tileWidth = std::stoi(value);
					else if (variable == "tileHeight")
						Mdata.tileHeight = std::stoi(value);
					else if (variable == "scaleX")
						Mdata.scaleX = std::stoi(value);
					else if (variable == "scaleY")
						Mdata.scaleY = std::stoi(value);

					else if (variable == "NumofRows")
						Mdata.NumofRows = std::stoi(value);
					else if (variable == "NumofColomn")
						Mdata.NumofColomn = std::stoi(value);

					else if (variable == "dataSize")
						Mdata.dataSize = std::stoi(value);

					else if (variable == "data")
					{
						
						Mdata.data = new int[Mdata.dataSize];

						int offset = 0;

						for (int i = 0; i < Mdata.dataSize ; i++)
						{
							int count = value.find(",", offset); // 3,7,11,15.....
							std::string v = value.substr(offset , count-offset);
							Mdata.data[i] = std::stoi(v);

							//std::cout << v << std::endl;
							//std::cout << i << "th "<<Mdata.data[i] << std::endl;

							offset = count + 1;
						}


						
					}
				}
				catch (const std::exception&)
				{
					std::cout << "error catch" << std::endl;


				}
				


			}
			
		}


		file.close();
	}
	else {
		std::cout << "unable to open file sry" << std::endl;
	}
	
}
