##############################################
# please add new classes in alphabetical order

AUTOMAKE_OPTIONS = foreign

# list of shared libraries to produce
lib_LTLIBRARIES = \
  libtrack_io.la

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -I$(ROOTSYS)/include

AM_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib \
  -L$(OFFLINE_MAIN)/lib64

pkginclude_HEADERS = \
  ActsSurfaceMaps.h \
  ActsTrackingGeometry.h \
  TpcSeedTrackMap.h \
  TpcSeedTrackMapv1.h \
  TrkrCluster.h \
  TrkrClusterv1.h \
  TrkrClusterv2.h \
  TrkrClusterv3.h \
  TrkrClusterContainer.h \
  TrkrClusterContainerv1.h \
  TrkrClusterContainerv2.h \
  TrkrClusterContainerv3.h \
  TrkrClusterHitAssoc.h \
  TrkrClusterHitAssocv1.h \
  TrkrClusterHitAssocv2.h \
  TrkrClusterHitAssocv3.h \
  TrkrClusterIterationMap.h \
  TrkrClusterIterationMapv1.h \
  TrkrDefs.h \
  TrkrHit.h \
  TrkrHitv1.h \
  TrkrHitv2.h \
  TrkrHitTruthAssoc.h \
  TrkrHitTruthAssocv1.h \
  TrkrHitSet.h \
  TrkrHitSetv1.h \
  TrkrHitSetContainer.h \
  TrkrHitSetContainerv1.h

ROOTDICTS = \
  TrkrCluster_Dict.cc \
  TrkrClusterv1_Dict.cc \
  TrkrClusterv2_Dict.cc \
  TrkrClusterv3_Dict.cc \
  TrkrClusterContainer_Dict.cc \
  TrkrClusterContainerv1_Dict.cc \
  TrkrClusterContainerv2_Dict.cc \
  TrkrClusterContainerv3_Dict.cc \
  TrkrClusterHitAssoc_Dict.cc \
  TrkrClusterHitAssocv1_Dict.cc \
  TrkrClusterHitAssocv2_Dict.cc \
  TrkrClusterHitAssocv3_Dict.cc \
  TrkrClusterIterationMap_Dict.cc \
  TrkrClusterIterationMapv1_Dict.cc \
  TrkrHit_Dict.cc \
  TrkrHitv1_Dict.cc \
  TrkrHitv2_Dict.cc \
  TrkrHitTruthAssoc_Dict.cc \
  TrkrHitTruthAssocv1_Dict.cc \
  TrkrHitSet_Dict.cc \
  TrkrHitSetv1_Dict.cc \
  TrkrHitSetContainer_Dict.cc \
  TrkrHitSetContainerv1_Dict.cc \
  TpcSeedTrackMap_Dict.cc \
  TpcSeedTrackMapv1_Dict.cc


pcmdir = $(libdir)
nobase_dist_pcm_DATA = \
  TrkrCluster_Dict_rdict.pcm \
  TrkrClusterv1_Dict_rdict.pcm \
  TrkrClusterv2_Dict_rdict.pcm \
  TrkrClusterv3_Dict_rdict.pcm \
  TrkrClusterContainer_Dict_rdict.pcm \
  TrkrClusterContainerv1_Dict_rdict.pcm \
  TrkrClusterContainerv2_Dict_rdict.pcm \
  TrkrClusterContainerv3_Dict_rdict.pcm \
  TrkrClusterHitAssoc_Dict_rdict.pcm \
  TrkrClusterHitAssocv1_Dict_rdict.pcm \
  TrkrClusterHitAssocv2_Dict_rdict.pcm \
  TrkrClusterHitAssocv3_Dict_rdict.pcm \
  TrkrClusterIterationMap_Dict_rdict.pcm \
  TrkrClusterIterationMapv1_Dict_rdict.pcm \
  TrkrHit_Dict_rdict.pcm \
  TrkrHitv1_Dict_rdict.pcm \
  TrkrHitv2_Dict_rdict.pcm \
  TrkrHitTruthAssoc_Dict_rdict.pcm \
  TrkrHitTruthAssocv1_Dict_rdict.pcm \
  TrkrHitSet_Dict_rdict.pcm \
  TrkrHitSetv1_Dict_rdict.pcm \
  TrkrHitSetContainer_Dict_rdict.pcm \
  TrkrHitSetContainerv1_Dict_rdict.pcm \
  TpcSeedTrackMap_Dict_rdict.pcm \
  TpcSeedTrackMapv1_Dict_rdict.pcm

# sources for io library
libtrack_io_la_SOURCES = \
  $(ROOTDICTS) \
  ActsSurfaceMaps.cc \
  TrkrClusterv1.cc \
  TrkrClusterv2.cc \
  TrkrClusterv3.cc \
  TrkrClusterContainer.cc \
  TrkrClusterContainerv1.cc \
  TrkrClusterContainerv2.cc \
  TrkrClusterContainerv3.cc \
  TrkrClusterHitAssoc.cc \
  TrkrClusterHitAssocv1.cc \
  TrkrClusterHitAssocv2.cc \
  TrkrClusterHitAssocv3.cc \
  TrkrClusterIterationMap.cc \
  TrkrClusterIterationMapv1.cc \
  TrkrDefs.cc \
  TrkrHitTruthAssocv1.cc \
  TrkrHitSet.cc \
  TrkrHitSetv1.cc \
  TrkrHitSetContainer.cc \
  TrkrHitSetContainerv1.cc \
  TrkrHitv1.cc \
  TrkrHitv2.cc \
  TpcSeedTrackMap.cc \
  TpcSeedTrackMapv1.cc

libtrack_io_la_LIBADD = \
  -lphool \
  -lActsCore

# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;

################################################
# linking tests

BUILT_SOURCES = testexternals.cc

noinst_PROGRAMS = \
  testexternals_track_io

#testexternals_track_util_SOURCES = testexternals.cc
#testexternals_track_util_LDADD = libtrack_util.la

testexternals_track_io_SOURCES = testexternals.cc
testexternals_track_io_LDADD = libtrack_io.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

################################################

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
