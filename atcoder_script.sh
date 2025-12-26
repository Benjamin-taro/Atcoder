#!/bin/bash
set -e

# cronは環境が薄いので明示
export HOME=/Users/iseyuki
export PATH=/usr/bin:/bin:/usr/sbin:/sbin

# ssh-agent を起動して、このスクリプト内で使えるようにする
eval "$(ssh-agent -s)" >/dev/null

# すでに登録済みなら何もしない / 無ければKeychain経由で追加
ssh-add -l >/dev/null 2>&1 || true
ssh-add --apple-use-keychain /Users/iseyuki/.ssh/id_ed25519 >/dev/null 2>&1 || true

# 終了時にagentを落とす（ゾンビ化防止）
trap 'ssh-agent -k >/dev/null 2>&1 || true' EXIT

commit_repo () {
  REPO_PATH="$1"
  COMMIT_MSG="$2"

  cd "$REPO_PATH" || return 0

  git add .

  if git diff --cached --quiet; then
    echo "[$REPO_PATH] No changes"
    return 0
  fi

  git commit -m "$COMMIT_MSG"
  git push origin main
}

commit_repo "/Users/iseyuki/atcoder.jp" "Automated commit (atcoder)"
commit_repo "/Users/iseyuki/programming practice/codeforces" "Automated commit (codeforces)"
