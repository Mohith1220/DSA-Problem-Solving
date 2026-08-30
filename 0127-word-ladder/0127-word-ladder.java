
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) {
            return 0;
        }

        Set<String> set = new HashSet<>(wordList);
        Queue<String> queue = new LinkedList<>();

        queue.offer(beginWord);
        int level = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();

            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                for (int j = 0; j < word.length(); j++) {

                    char[] chars = word.toCharArray();

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (chars[j] == c) {
                            continue;
                        }

                        chars[j] = c;
                        String nextWord = new String(chars);
                        if (nextWord.equals(endWord)) {
                            return level + 1;
                        }
                        if (set.contains(nextWord)) {
                            queue.offer(nextWord);
                            set.remove(nextWord);
                        }
                    }
                }
            }

            level++;
        }

        return 0;
    }
}

