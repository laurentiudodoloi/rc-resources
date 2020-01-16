#include <string>

class ColabApi {
private:
	static ColabApi *instance;

	ColabApi();

public:
	static ColabApi *getInstance() {
		if (!instance) {
			instance = new ColabApi;
		}

		return instance;
	}

	static std::string getFileList();
	static std::string getFileContent(std::string file);
	static std::string writeToFile(std::string file, std::string content);
};
