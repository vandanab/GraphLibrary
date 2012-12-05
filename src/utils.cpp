/**
* utility functions like imprt export
*/
#include <unordered_map>
#include <utility>
#include "utils.h"
#include "gml_parser.h"

namespace lib {
	Graph<int> import_gml(std::string filename) {
		lib::Graph<int> g;
		std::unordered_map<long, int> id_ordinal_map;

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
					if (list->kind == GML_LIST) //graph
					{
						GML_pair* list1 = list->value.list;
						while (list1) {
							//printf("%s\n", list1->key);
							if (!strcmp(list1->key, "node")) {
								GML_pair* list2 = list1->value.list;
								while (list2) {
									//printf("%s\n", list2->key);
									if(!strcmp(list2->key, "id")) {
										int node_ordinal = g.add_node((int)list2->value.integer);
										std::pair<long, int> entry (list2->value.integer,node_ordinal);
										id_ordinal_map.insert(entry);
									}
									list2 = list2->next;
								}
							}
							else if (!strcmp(list1->key, "edge")) {
								GML_pair* list2 = list1->value.list;
								int src_node = -1, dest_node = -1;
								while (list2) {
									//printf("%s\n", list2->key);
									if (!strcmp(list2->key, "source")) {
										src_node = id_ordinal_map[list2->value.integer];
										//printf("%d\n", list2->value.integer);
									} else if (!strcmp(list2->key, "target")) {
										dest_node = id_ordinal_map[list2->value.integer];
										//printf("%d\n", list2->value.integer);
									}
									list2 = list2->next;
								}
								if (src_node > 0 && dest_node > 0) {
									g.add_edge(src_node, dest_node);
								}
							}
							list1 = list1->next;
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