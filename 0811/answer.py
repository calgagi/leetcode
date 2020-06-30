class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        dictionary = {}
        for domain in cpdomains:
            domain = domain.split(" ")
            count = int(domain[0])
            domains = domain[1].split(".")
            string = ""
            for i in domains[::-1]:
                if string == "":
                    string = i + string
                else:
                    string = i + "." + string
                if string not in dictionary:
                    dictionary[string] = count
                else:
                    dictionary[string] += count

        rList = []
        for key, value in dictionary.iteritems():
            rList.append(str(value) + " " + key)
        return rList


            
