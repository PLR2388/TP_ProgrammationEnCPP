# Introduction

The objective of this project was to create a graphical interface for the SAAQ (Société de l'assurance automobile du Québec) that allows assigning vehicles with valid license plates and a VIN (Vehicle Identification Number) to an owner.

This project was not delivered to the SAAQ as it was just a context to apply various concepts in C++.

The project spanned the entire Fall 2019 semester (September to December) and was divided into four practical assignments. Each assignment advanced the functionality of the project.

The first assignment had us develop two functions: one to validate the license plates of passenger vehicles and trucks, and another to validate a VIN.

The second assignment had us develop the `Vehicle` class (source folder), document the existing code with DOXYGEN, and use namespaces.

The third assignment had us develop the following class hierarchy, implement tests with GoogleTest, and apply contract theory.

![Class Hierarchy](https://i.ibb.co/y8BQ3nL/image.png)

The final assignment (the only one done in pairs) had us develop a Qt interface and manage exceptions.

# Project Structure

The project contains:
  - A `source` folder, which is a static library containing the business logic classes.
  - A `SaaqGUI` folder, which contains the files for generating the Qt graphical interface.
  - A `tp4_Testeur` folder, which contains the GoogleTest tests for the classes.

# Libraries

This project was compiled with the Eclipse IDE. It requires:

* Qt
* GoogleTest
* Linking with the static source library
