#! /usr/bin/env bash

if [[ ! $(ls ../projectile_sim) ]]; then
    echo "E: must be in project root directory"
    exit 1
fi

if [[ "$1" == "" ]]; then
    echo "E: version not given"
    exit 1
fi

if [[ "$2" == "" ]]; then
    echo "E: message not given"
    exit 1
fi

version="$1"
message="$2"

if [[ "$3" != "" ]]; then
    echo "E: superfluous arguments"
    exit 1
fi

echo "$1" > version.txt
grep -E "^v[0-9]*\.[0-9]*\.[0-9]*$" version.txt

echo "checking network connection..."
if [[ ! $(ping -c1 debian.org) ]]; then
    echo "E: no network connection"
    exit 1
fi

echo "switching to branch main..."
git switch main

echo "+++"
echo "version: $1"
echo "message: $2"
echo "+++"
read -rep "Are you sure you want to tag and push this? " cont

case "$cont" in
    y|Y)
        echo "creating tag..."
        git tag -a $version -m $message
        echo "pushing to origin..."
        git push --tags
        ;;
    *)
        echo "cancelling..."
        exit 1
        ;;
esac
