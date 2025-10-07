#!/usr/bin/env bash
set -euo pipefail

contest="$1"
letters=${2:-"a b c d e f"}

# 親フォルダ（例: abc426）を作成
mkdir -p "$contest"

for p in $letters; do
  dir="${contest}/${contest}_${p}"  # ← contestフォルダの中に作成される
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
