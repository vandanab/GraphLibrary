/**
 * attribute_service.h
 * @author: GraphLib Team
 * AttributeService class which saves attributes for nodes and edges of the graph. Can be made more sophisticated.
 * It makes sense to have a service associated with data structures requiring common functionality which provides that functionality(like an iterator).
 */
#include<unordered_map>
#include<string>
#include<vector>
#include<utility>
#ifndef ATTRIBUTE_SERVICE_H
#define ATTRIBUTE_SERVICE_H 

namespace lib {

	class AttributeService {
		std::unordered_map<std::string, std::string> str_attribs;
		std::unordered_map<std::string, double> num_attribs;

	public:
		AttributeService() = default;
		//move constructor
		AttributeService(AttributeService&& a) = default;
		AttributeService& operator=(AttributeService&& a) = default;
		//copy constructor
		AttributeService(const AttributeService& a) = default;
		AttributeService& operator=(const AttributeService& a) = default;

		~AttributeService() = default;

		void add_attribute(std::string key, std::string value) {
			str_attribs[key] = value;
		}

		void add_attribute(std::string key, double value) {
			num_attribs[key] = value;
		}

		//TODO:check has key and raise exception
		double get_attribute(std::string key) {
			return num_attribs[key];
		}

		std::string get_string_attribute(std::string key) {
			return str_attribs[key];
		}
	
		std::vector<std::pair<std::string, double> > get_attributes() {
			std::vector<std::pair<std::string, double> > attributes;
			for(auto& x: num_attribs) {
				attributes.push_back(std::make_pair(x.first, x.second));
			}
			return attributes;
		}

		std::vector<std::pair<std::string, std::string> > get_string_attributes() {
			std::vector<std::pair<std::string, std::string> > attributes;
			for(auto& x: str_attribs) {
				attributes.push_back(std::make_pair(x.first, x.second));
			}
			return attributes;
		}
	};
}
#endif
