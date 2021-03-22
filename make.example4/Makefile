# Try to answer the following questions by yourself first.
# 1. What is overall behavior of this Makefile?
# 2. Explanin briefly what each target do.
# 3. If the weather is not sunny, how can we force the compilation?
# 4. If there exist helloworld-dist.tar.gz, will tar command run?

# Default target.
all: build

# Before we build, we check the weather first.
# If it is sunny, then we explicitly call "make helloworld".
build: check_weather
	@if grep -q Sunny weather; then\
		echo "It is sunny. I am happy.";\
		make helloworld;\
	else\
		echo "Nope!";\
	fi

# Build the C++ application.
helloworld: hello_world.cc
	@echo "Compiling..."
	$(CXX) $< -o $@

# Target to create an archive file.
pack: helloworld-dist.tar.gz

# Target for make, so it do not create this file again if it is already exist and
# up-to-date.
helloworld-dist.tar.gz:
	tar czf helloworld-dist.tar.gz --exclude='helloworld-dist.tar.gz' --exclude='.git' --exclude='helloworld' --exclude='weather' *

# Target to check the weather.
# It depends on a file named weather.
check_weather: weather

# Literally check the weather, and cache the result
# in a file named weather.
weather:
	@echo "Checking weather"
	@curl -Ss 'https://wttr.in?0&T&Q' | cut -c 16- | head -2 | xargs echo > ./weather

clean:
	-rm -f weather
	-rm -f helloworld
	-rm -f helloworld-dist.tar.gz