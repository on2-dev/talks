---
marp: true
theme: gaia
backgroundColor: dark
_color: white
---

# **React Admin**

---

# **~~React~~ Admin**

---

# **Providers**

---

## Data Providers

![dataProvider](./assets/data-provider.png)

---

## Data Providers

```js
const dataProvider = {
  getList: (resource, params) => Promise,
  getOne: (resource, params) => Promise,
  getMany: (resource, params) => Promise,
  getManyReference: (resource, params) => Promise,
  create: (resource, params) => Promise,
  update: (resource, params) => Promise,
  updateMany: (resource, params) => Promise,
  delete: (resource, params) => Promise,
  deleteMany: (resource, params) => Promise,
};
```

---

![bg right](./assets/mun-ra.png)

## Data Providers

![width:200](./assets/rest-in-peace.png)
[ra-data-simple-rest](https://github.com/marmelab/react-admin/tree/master/packages/ra-data-simple-rest)
![width:200](./assets/graphql.png)
[ra-data-graphql-simple](https://github.com/marmelab/react-admin/tree/master/packages/ra-data-graphql-simple)
![width:200](./assets/many-things.png)
[Available Providers](https://marmelab.com/react-admin/DataProviders.html)

---

## Auth Providers

## ![](./assets/auth-provider.png)

## Auth Providers

```js
const authProvider = {
  // authentication
  login: (params) => Promise.resolve(),
  checkError: (error) => Promise.resolve(),
  checkAuth: (params) => Promise.resolve(),
  logout: () => Promise.resolve(),
  getIdentity: () => Promise.resolve(),
  // authorization
  getPermissions: (params) => Promise.resolve(),
};
```

---

## Auth Providers

AWS Amplify: MrHertal/react-admin-amplify
AWS Cognito: thedistance/ra-cognito
Firebase Auth (Google, Facebook, Github etc): benwinding/react-admin-firebase

---

# **i18n**

---

# **View**

como instalar?
como criar componente?
que componentes temos disponíveis?
como fazer `fetch`?
login?
