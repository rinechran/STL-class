<%--
  Created by IntelliJ IDEA.
  User: rinechran
  Date: 2020-09-25
  Time: 오전 2:49
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
    <p3> param 액션 태그</p3>
    <jsp:forward page="param01_data.jsp">
      <jsp:param name="id" value="2013150032"/>
      <jsp:param name="name" value='<%=java.net.URLEncoder.encode("정은식","UTF-8")%>'/>
    </jsp:forward>
      
  </body>
</html>
