#ifndef _PATIENT_H_
#define _PATIENT_H_
#include "Patient.h"

#include <string>


class Patient {
private:
	std::string firstName{}, lastName{}, insuranceName{}, policyNumber{};
	int phoneNumber{}, birthdate{}, SSN{};

public:
	Patient(std::string firstName, std::string lastName, std::string insuranceName, std::string policyNumber, int phoneNumber, int birthdate, int SSN) {

		this->firstName = firstName;
		this->lastName = lastName;
		this->insuranceName = insuranceName;
		this->policyNumber = policyNumber;
		this->phoneNumber = phoneNumber;
		this->birthdate = birthdate;
		this->SSN = SSN;

	}

	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	std::string getInsuranceName() { return insuranceName; }
	std::string getPolicyNumber() { return policyNumber; }
	int getPhoneNumber() { return phoneNumber; }
	int getBirthdate() { return birthdate; }
	int getSSN() { return SSN; }

};

#endif