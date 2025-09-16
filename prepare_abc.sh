#!/usr/bin/env bash
set -euo pipefail

contest="$1"
letters=${2:-"a b c d e f"}

for p in $letters; do
  dir="${contest}_${p}"
  url="https://atcoder.jp/contests/${contest}/tasks/${contest}_${p}"
  mkdir -p "$dir"
  (
    cd "$dir"
    oj-template "$url" > main.cpp
    oj d -d test "$url" || true
  )
  echo "Prepared $dir"
done
echo "Done."
