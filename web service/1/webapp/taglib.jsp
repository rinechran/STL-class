<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<html>
<head>
    <title>Jung Eun Sik</title>
</head>
<body>
    <c:forEach var="k" begin="1" end="10" step="1">
        <c:out value="${k}" />
    </c:forEach>
   
</body>
</html>