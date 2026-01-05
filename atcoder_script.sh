#!/bin/bash
set -e

export HOME=/Users/iseyuki
export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin

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
  GIT_SSH_COMMAND="ssh -i $HOME/.ssh/id_ed25519 -o IdentitiesOnly=yes -o StrictHostKeyChecking=accept-new" git push origin main
}

commit_repo "/Users/iseyuki/atcoder.jp" "Automated commit (atcoder)"
commit_repo "/Users/iseyuki/programming practice/codeforces" "Automated commit (codeforces)"
