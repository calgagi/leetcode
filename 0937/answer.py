class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        letterLogs = []
        digitLogs = []
        for log in logs:
            if log.split(" ")[1].isdigit():
                digitLogs.append(log)
            else:
                letterLogs.append(log)
                
        sortedLetterLogs = []
        sortedLetterLogs2 = []
        for log in letterLogs:
            sortLog = log.split(" ")
            sortLog.append(sortLog.pop(0))
            sortLog = " ".join(sortLog)
            found = 0
            for i in range(len(sortedLetterLogs)):
                if sortLog < sortedLetterLogs[i]:
                    sortedLetterLogs.insert(i, sortLog)
                    sortedLetterLogs2.insert(i, log)
                    found = 1
                    break
            if not found:
                sortedLetterLogs.append(sortLog)
                sortedLetterLogs2.append(log)

        return sortedLetterLogs2 + digitLogs
