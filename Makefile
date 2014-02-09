CXX = clang++
SDL = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_gfx
CXXFLAGS = -Wall -c -std=c++11 -stdlib=libc++
LDFLAGS = -stdlib=libc++ $(SDL)
# The source and build output directories
SRC = src
BUILD = build
# Generate listing of all our source and object files
SOURCES = $(wildcard $(SRC)/*.cpp)
OBJS = $(addprefix $(BUILD)/, $(notdir $(SOURCES:.cpp=.o)))
# Executables will be written to the top level of the repo under out/
EXE = asteroids

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

$(BUILD)/%.o: $(SRC)/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $< -o $@

# Make sure the build directory exists
$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm $(BUILD)/*.o && rm $(EXE)

