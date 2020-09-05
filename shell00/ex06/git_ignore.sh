#!/bin/bash
git status -s --ignored | grep '!!' | sed 's/!! //'
