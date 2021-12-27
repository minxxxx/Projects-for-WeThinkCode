#!/usr/bin/env bash
mvn clean package > .maven-build-log && java -cp target/swingy-1.0.jar packages.App console test.txt