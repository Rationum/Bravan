#pragma once
#include <string>

class SimpleSaveAndLoad
{
private: // Properties Declared
	std::string _SaveLoadLabel;
	int _SaveLoadID;
	int _SaveLoadRate;

public: // Constructor & Methods Declared
	SimpleSaveAndLoad();

	// Getters
	std::string get_SLLabel() const;
	int get_SLID() const;
	int get_SLRate() const;

	// Setters
	void set_SLLabel(std::string para);
	void set_SLID(int para);
	void set_SLRate(int para);

	// Save
	bool saveRecord(SimpleSaveAndLoad para);

	// Load
	friend std::istream& operator >> (std::istream& is, SimpleSaveAndLoad& s);	
};