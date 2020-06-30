class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        num = 0
        seen = {}
        for i in emails:
            parts = i.split("@")
            parts[0] = parts[0].split("+")[0]
            parts[0] = parts[0].replace(".", "")
            new_email = parts[0] + parts[1]
            if new_email not in seen:
                num += 1
                seen[new_email] = True
        return num
