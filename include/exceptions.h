/**
 * exceptions.h
 * @author: GraphLib Team (?)
 * Contains the exception classes used by the Graph Library.
 */
#include<exception>
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class InvalidAccessException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "invalid access";
	}
};
#endif
