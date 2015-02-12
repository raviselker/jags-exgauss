SUBDIRS = distributions

jagsmod_LTLIBRARIES = exgauss.la

exgauss_la_SOURCES = exgauss.cc

exgauss_la_CPPFLAGS = -I$(includedir)/JAGS

exgauss_la_LIBADD = distributions/exgaussdist.la

if WINDOWS
exgauss_la_LIBADD += -ljags-$(JAGS_MAJOR) -ljrmath-0
else
exgauss_la_LIBADD += -ljags -ljrmath
endif

exgauss_la_LDFLAGS = -module -avoid-version
if WINDOWS
exgauss_la_LDFLAGS += -no-undefined
endif
