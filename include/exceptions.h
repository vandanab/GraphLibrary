/**
 * exceptions.h
 * @author: GraphLib Team (?)
 * Contains the exception classes used by the Graph Library.
 */
#include<exception>
#include<string>
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class InvalidAccessException : public std::exception {
	std::string msg;
public:
	InvalidAccessException(std::string message) {
		msg = message;
	}
	InvalidAccessException() {
		msg = "Invalid access";
	}
	virtual const char* what() const throw() {
		return (char *)msg.c_str();
	}
};
#endif
