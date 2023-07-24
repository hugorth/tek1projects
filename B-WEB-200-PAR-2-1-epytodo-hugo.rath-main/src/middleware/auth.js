const jwt = require('jsonwebtoken');
const SECRET = process.env.SECRET;

function authenticateToken(req, res, next) {
  const token = req.headers.authorization;

  if (!token) {
    return res.status(401).json({ msg: 'No token, authorization denied' });
  }

  jwt.verify(token, SECRET, (err, decodedToken) => {
    if (err) {
      return res.status(401).json({ msg: 'Token is not valid' });
    }

    req.user = decodedToken.user;
    next();
  });
}

module.exports = authenticateToken;
