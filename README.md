# Readme
This is a small hobby project were I try to create a blend from
a few very closely related games.
For the economical side I would like to combine "Settlers 3", "Settlers 4"
and the "Cultures"-series.
For the competitive side I would like to take some inspirations from
"Stronghold" and the "Cultures"-series.
Combining the skills and equipments systems from "Cultures" and "Spellforce"
I hope to create a very elegant economy heavy RTS with RPG elements.

At the moment I am collecting my ideas and writing them down.
While also slowly beginning to lay foundations for the code.

If you have an idea or wish to contribute please create an issue on the page.

## Building

1. Understand that the code is free as in freedom not **free as in beer**.
	If you wish to be a filthy pirate I hope you will spend the first ten years 
	of your afterlife centering divs with Malbolge and should I hear of it
	I may come after you to the extent that your local copyright-laws warrant.
2. Ensure you paid for the program and proceed to build
3. Install the build tools I used ore something equivalent:
	- CMake
	- Ninja
	- GCC
4. Open terminal in the main folder
5. Run CMake
	``` 
		cmake -B ./build -S ./code/
	```
6. Build project
	``` 
		cmake --build ./build
	```