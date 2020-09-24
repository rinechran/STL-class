<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 3:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <%
        request.setCharacterEncoding("UTF-8");
        String userId  = request.getParameter("id");
        String password = request.getParameter("pass");

        if( userId.equals("정은식") && password.equals("2013150032") ){
            response.sendRedirect("response01_success.jsp");
        }else{
            response.sendRedirect("response01_failed.jsp");
        }
    %>

</body>
</html>
