#include "Patient.h"
#include <string>


Patient::Patient(std::string firstName, std::string lastName, std::string insuranceName, std::string policyNumber, int phoneNumber, int birthdate, int SSN) {

	this->firstName = firstName;
	this->lastName = lastName;
	this->insuranceName = insuranceName;
	this->policyNumber = policyNumber;
	this->phoneNumber = phoneNumber;
	this->birthdate = birthdate;
	this->SSN = SSN;
}

std::string Patient::getFirstName() { return firstName; }
std::string Patient::getLastName() { return lastName; }
std::string Patient::getInsuranceName() { return insuranceName; }
std::string Patient::getPolicyNumber() { return policyNumber; }
int Patient::getPhoneNumber() { return phoneNumber; }
int Patient::getBirthdate() { return birthdate; }
int Patient::getSSN() { return SSN; }