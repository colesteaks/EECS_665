all: compile

build:
	java -classpath antlrworks-1.4.3.jar org.antlr.Tool Lab5.g

compile: build
	javac -classpath antlrworks-1.4.3.jar *.java

run:
	java -classpath .:antlrworks-1.4.3.jar Lab5Parser

edit:
	java -jar antlrworks-1.4.3.jar

clean:
	$(RM) -r *.java *.class *.tokens output
