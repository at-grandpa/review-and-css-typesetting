#!/usr/bin/env sh

set -eu

npx http-server ./articles   -p 8989 -s -c-1 --cors &
npx http-server /vivliostyle -p 8000 -s -c-1 --cors
