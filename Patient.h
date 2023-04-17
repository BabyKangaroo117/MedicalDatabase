#ifndef _PATIENT_H_
#define _PATIENT_H_

#include <string>


class Patient {
private:
	std::string firstName{}, lastName{}, insuranceName{}, policyNumber{};
	int phoneNumber{}, birthdate{}, SSN{};

public:
	Patient(std::string firstName, std::string lastName, std::string insuranceName, std::string policyNumber, int phoneNumber, int birthdate, int SSN);

	std::string getFirstName();
	std::string getLastName();
	std::string getInsuranceName();
	std::string getPolicyNumber();
	int getPhoneNumber();
	int getBirthdate();
	int getSSN();

};

#endif