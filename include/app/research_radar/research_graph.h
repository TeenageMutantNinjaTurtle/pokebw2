#ifndef POKEBW2_APP_RESEARCH_RADAR_RESEARCH_GRAPH_H
#define POKEBW2_APP_RESEARCH_RADAR_RESEARCH_GRAPH_H

#include "types.h"
#include "struct_decls.h"

// The Research Radar's graph of a survey's answers (research_graph.c)
// The names of these functions and types are ours

// Where the graph goes when it ends
enum {
    RESEARCH_GRAPH_NEXT_TOP,
    RESEARCH_GRAPH_NEXT_EXIT,
};

ResearchGraph *ResearchGraph_Create(ResearchCommon *common);
void ResearchGraph_Delete(ResearchGraph *graph);
void ResearchGraph_Main(ResearchGraph *graph);
BOOL ResearchGraph_IsEnd(ResearchGraph *graph);
u32 ResearchGraph_GetNext(ResearchGraph *graph);

#endif // POKEBW2_APP_RESEARCH_RADAR_RESEARCH_GRAPH_H
