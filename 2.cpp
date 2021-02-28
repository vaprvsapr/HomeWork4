#include <iostream>
#include <ctime>
#include <boost/circular_buffer.hpp>
#include <utility>
using namespace std;

class Logger {
private:
	boost::circular_buffer<pair<string, string>> cb;
	const int capacity;
public:
	Logger(const int& cp) : capacity(cp) {
		cb.set_capacity(capacity);
	}

	void NewLog(const string& email) {
		string date_time = 
			static_cast<string>(__DATE__) + 
			" " + 
			static_cast<string>(__TIME__);
		cb.push_back(make_pair(email, date_time));
	}

	void PrintData() const {
		for (auto pice_of_data : cb) {
			cout << "email: "
				<< pice_of_data.first
				<< ", "
				<< pice_of_data.second;	
			cout << endl;
		}
	}
};

int main() {
	Logger lg(3);
	lg.NewLog("vaprvsapr@mail.ru");
	lg.NewLog("stepanov.nk@phystech.edu");
	lg.NewLog("BigLover228.gmail.com");
	lg.PrintData();

	cout << "=============" << endl;

	lg.NewLog("anonimus@yandex.ru");
	lg.PrintData();
}
