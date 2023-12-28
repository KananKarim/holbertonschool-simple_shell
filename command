#!/bin/bash

# Add all changes to the staging area
git add .

# Prompt for commit message
read -p "Enter commit message: " message

# Commit changes with the provided message
git commit -m "$message"


# Push changes to the remote repository
git push
