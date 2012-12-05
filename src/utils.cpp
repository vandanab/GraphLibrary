/**
* utility functions like imprt export
*/

#include "utils.h"
#include "gml_parser.h"

namespace lib {
	Graph<int> import_gml(std::string filename) {
		lib::Graph<int> g;
		FILE* file = fopen (filename.c_str(), "r");
		if (!file)
			printf ("\n No such file: %s", filename.c_str());
		else {
			struct GML_pair* list;
			struct GML_stat* stat=(GML_stat*)malloc(sizeof(struct GML_stat));
			stat->key_list = NULL;

			GML_init();
            list = GML_parser(file, stat, 0);

			if (stat->err.err_num == GML_OK) {
				while (list) {
					printf("%s\n", list->key);
					if (!strcmp(list->key, "node")) {
						list = list->next;
						if(!strcmp(list->key, "id")) {
							g.add_node(list->value.integer);
						}
					}
					else if (!strcmp(list->key, "edge")) {
						list = list->next;
						if (!strcmp(list->key, "source")) {
							int src_node = list->value.integer;
							list = list->next;
							if (!strcmp(list->key, "target")) {
								int dest_node = list->value.integer;
								g.add_edge(src_node, dest_node);
							}
						}
					}
					list = list->next;
				}
				GML_free_list(list, stat->key_list);
			}
			else {
				//todo: throw exception
				printf ("Error reading line %d column %d of %s:\n", 
							stat->err.line, stat->err.column, filename.c_str());
			}
		}
		return g;
	}
}