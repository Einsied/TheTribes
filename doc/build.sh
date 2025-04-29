#!/bin/bash

# This file permits you to build the manual on linux system,
# assuming the package texlive-full was installed.
# If you use a different operating system or distribution
# you can take these commands as an inspiration for your
# compilation process.

# The name of the main project

project_name="cultures_like"

# Build to initialize everything
pdflatex $project_name .tex
# Create the glossaries so we can reference them
makeglossaries $project_name
# Rebuild with the references
pdflatex $project_name .tex
# Rebuild to fix the page-numbers moved by creating the table of contents
# and the glossaries
pdflatex $project_name .tex
