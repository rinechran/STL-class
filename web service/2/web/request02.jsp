<%@ page import="java.util.Enumeration" %><%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 3:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%

    Enumeration en = request.getHeaderNames();
    while (en.hasMoreElements()) {
        String headerName = (String) en.nextElement();
        String headerValue = request.getHeader(headerName);
%>
<%= headerName %> :<%= headerValue %> <br>

<%
    }
%>
</body>
</html>
