MAINTAINERCLEANFILES = Makefile.in

SUBDIRS =

AUTOMAKE_OPTIONS = no-dependencies

#A test
crofchantest_SOURCES= unittest.cpp crofchantest.hpp crofchantest.cpp
crofchantest_CPPFLAGS= -I$(top_srcdir)/src/
crofchantest_LDFLAGS= -static
crofchantest_LDADD= $(top_builddir)/src/rofl/librofl_common.la -lcppunit

#Tests

check_PROGRAMS= crofchantest
TESTS = crofchantest
