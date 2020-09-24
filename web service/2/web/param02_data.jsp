<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 3:21
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <%
        String  title = request.getParameter("title");
    %>
    <h3> <%= java.net.URLDecoder.decode(title,"UTF-8") %></h3>
    TODAY is : <%= request.getParameter("date")%>
</body>
</html>
