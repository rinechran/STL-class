<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 3:20
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <jsp:forward page="param02_data.jsp">
        <jsp:param name="title" value='<%= java.net.URLEncoder.encode("오늘의 날짜와 시간","UTF-8") %>'/>
        <jsp:param name="date" value='<%= java.util.Calendar.getInstance().getTime() %>'/>
    </jsp:forward>
</body>
</html>
